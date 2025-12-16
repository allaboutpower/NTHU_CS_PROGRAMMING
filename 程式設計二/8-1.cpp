
class Object {
    public:
        Object(double W);
        void setCircle(double X, double Y, double R);
        void setSpeed(double Vx, double Vy);
        double &getSpeedX();
        double &getSpeedY();
        double &getX();
        double &getY();
        double &getR();
        const double &getWeight() const;
        const double &getSpeedX() const;
        const double &getSpeedY() const;
        double getVelocity() const;
        double getAngle() const;
        const double &getX() const;
        const double &getY() const;
        const double &getR() const;
    private:
        double weight;
        double vx, vy;
        double x, y, r;
};

/////////////////////
#include<cmath>
#include<vector>

struct Vector2{
	Vector2():x{0},y{0}{}
	Vector2(double X, double Y):x{X}, y{Y}{}
	Vector2 operator + (const Vector2 &rhs)const{
		return {x+rhs.x, y+rhs.y};
	}
	Vector2 operator - (const Vector2 &rhs)const{
		return {x-rhs.x, y-rhs.y};
	}
	Vector2 operator * (double s)const{
		return {x*s, y*s};
	}

	double operator * (const Vector2 &rhs)const{
		return x*rhs.x+y*rhs.y;
	}
	Vector2 operator / (double s)const{
		return {x/s, y/s};
	}
	double len()const{
		return std::sqrt(x*x+y*y);
	}
	Vector2 normalized()const{
		double lengh = len();
		if(lengh==0)return{0,0};
		return{x/lengh, y/lengh};
	}
	double x,y;
};

class PhysicEngine{
public:
	constexpr static double G = 9.8;
	PhysicEngine():fps{0}, dt{0}{}
	void setFPS(unsigned FPS){fps=FPS, dt=1/FPS;}
	void addObject(const Object &obj){
		objects.push_back(obj);
	}
	const std::vector<Object> &getObjects(){
		return objects;
	}
	// 1 update
	bool forward(){
		bool isCollide = false;
		for(auto &obj:objects){
			obj.getSpeedY()-=G*dt;
			obj.getX()+=obj.getSpeedX()*dt;
			obj.getY()+=obj.getSpeedY()*dt;
		}
		// 2 collision
		for(size_t i=0; i<objects.size(); i++){
			for(size_t j=i+1; j<objects.size(); j++){
				Object &a = objects[i];
				Object &b = objects[j];
				double dx = b.getX()-a.getX();
				double dy = b.getY()-a.getY();
				double dis = std::sqrt(dx*dx+dy*dy);
				if(dis<=a.getR()+b.getR()){
					isCollide |= resolveObjectCollision(a,b);
				}
			}
		}
		// 3 ground
		for(auto &obj:objects){
			if(obj.getY()<=obj.getR()){
				obj.getSpeedY() = std::abs(obj.getSpeedY());
			}
		}
		return isCollide;
	}
	
private:
	bool resolveObjectCollision(Object &a, Object &b){
		Vector2 normal = Vector2{b.getX()-a.getX(), b.getY()-a.getY()}.normalized();
		Vector2 dv{b.getSpeedX()-a.getSpeedX(), b.getSpeedY()-a.getSpeedY()};
		double vn  = dv*normal;
		if(vn>0)return false;
		double impulse = 2*vn/(a.getWeight()+b.getWeight());
		a.getSpeedX()+=impulse*b.getWeight()*normal.x;
		a.getSpeedY()+=impulse*b.getWeight()*normal.y;
		b.getSpeedX()-=impulse*a.getWeight()*normal.x;
		b.getSpeedY()-=impulse*a.getWeight()*normal.y;
		return true;
	}
	std::vector<Object> objects;
	unsigned fps;
	double dt;
};
