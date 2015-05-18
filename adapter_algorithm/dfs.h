/* generic dfs utility */

#include <functional>
#include <assert.h>

template <typename T, typename func, typename container_type>
void dfs(const T &node, func terminate, container_type getNext){
    class _impl {
        public:
            _impl(func _e, container_type _n) : m_terminate(std::move(_e)), m_getNext(std::move(_n)) {}
            void dfs(const T &node){
                if (m_terminate(node)){
                    return;
                }
                auto children = m_getNext(node);
                for (const auto &iter : children){
                    dfs(iter);
                }
            }
        private:
            func m_terminate;
            container_type m_getNext;
    };
    _impl(terminate, getNext).dfs(node);
}
