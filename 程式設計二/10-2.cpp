#include <cstddef>
#include <iterator>

namespace IPHTC {
    template<typename T>//任意iterator

    class Enumerate {
    private:
        using TIter = decltype(std::begin(std::declval<T>()));
        using TVal = decltype(*std::begin(std::declval<T>()));

    public:
        class iterator {
        public://符合標準
            using value_type = std::pair<const std::size_t &, TVal>;
            using reference = value_type;
            using pointer = value_type*;
            using difference_type = std::ptrdiff_t;
            using iterator_category = std::input_iterator_tag;

        public://
            iterator() = default;
            iterator(std::size_t index, TIter it) : m_size{index}, m_it{it} {}
            iterator &operator++ () { ++m_size; ++m_it; return *this; }
            bool operator== (const iterator &rhs) const { return m_it == rhs.m_it; }
            bool operator!= (const iterator &rhs) const { return m_it != rhs.m_it; }
            reference operator* () const { return {m_size, *m_it}; }

        private:
            std::size_t m_size;
            TIter m_it;
        };

        Enumerate(T iterable) : m_iterable{iterable} {
            m_size = std::distance(std::begin(m_iterable), std::end(m_iterable));
        }
        iterator begin() const { return iterator{0, std::begin(m_iterable)}; }
        iterator end() const { return iterator{m_size, std::end(m_iterable)}; }
        const std::size_t &size() const { return m_size; }

    private:
        T m_iterable;
        std::size_t m_size;
    };
};

// Do not modify the following contents! Otherwise the compilation will fail.
