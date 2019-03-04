/*
 * (C) 2017 The University of Chicago
 * 
 * See COPYRIGHT in top-level directory.
 */
#include <vector>
#include <thallium/endpoint.hpp>
#include <thallium/engine.hpp>
#include <thallium/margo_exception.hpp>

namespace thallium {

endpoint::endpoint(engine& e, hg_addr_t addr, bool take_ownership)
: m_engine(&e), m_addr(HG_ADDR_NULL) {
    if(take_ownership) {
        m_addr = addr;
    } else {
        margo_addr_dup(m_engine->m_mid, addr, &m_addr);
    }
}

endpoint::endpoint(const endpoint& other)
: m_engine(other.m_engine) {
	if(other.m_addr != HG_ADDR_NULL) {
		hg_return_t ret = margo_addr_dup(m_engine->m_mid, other.m_addr, &m_addr);
        MARGO_ASSERT(ret, margo_addr_dup);
	} else {
		m_addr = HG_ADDR_NULL;
	}
}

endpoint& endpoint::operator=(const endpoint& other) {
    hg_return_t ret;
	if(&other == this) return *this;
	if(m_addr != HG_ADDR_NULL) {
		ret = margo_addr_free(m_engine->m_mid, m_addr);
        MARGO_ASSERT(ret, margo_addr_free);
	}
    m_engine = other.m_engine;
	if(other.m_addr != HG_ADDR_NULL) {
        ret = margo_addr_dup(m_engine->m_mid, other.m_addr, &m_addr);
        MARGO_ASSERT(ret, margo_addr_dup);
	} else {
		m_addr = HG_ADDR_NULL;
	}
	return *this;
}

endpoint& endpoint::operator=(endpoint&& other) {
	if(&other == this) return *this;
	if(m_addr != HG_ADDR_NULL) {
        hg_return_t ret = margo_addr_free(m_engine->m_mid, m_addr);
        MARGO_ASSERT(ret, margo_addr_free);
	}
    m_engine = other.m_engine;
	m_addr = other.m_addr;
	other.m_addr = HG_ADDR_NULL;
	return *this;
}

endpoint::~endpoint() {
	if(m_addr != HG_ADDR_NULL) {
        hg_return_t ret = margo_addr_free(m_engine->m_mid, m_addr);
        MARGO_ASSERT(ret, margo_addr_free);
	}
}

endpoint::operator std::string() const {
    // TODO throw an exception if one of the following calls fail
	if(m_addr == HG_ADDR_NULL) return std::string();

	hg_size_t size;
    hg_return_t ret = margo_addr_to_string(m_engine->m_mid, NULL, &size, m_addr);
    MARGO_ASSERT(ret, margo_addr_to_string);

	std::vector<char> result(size);

    ret = margo_addr_to_string(m_engine->m_mid, &result[0], &size, m_addr);
    MARGO_ASSERT(ret, margo_addr_to_string);
	return std::string(result.data());
}

hg_addr_t endpoint::get_addr(bool copy) const {
    if(!copy || m_addr == HG_ADDR_NULL) return m_addr;
    if(m_engine == nullptr) return HG_ADDR_NULL;
    hg_addr_t new_addr;
    hg_return_t ret = margo_addr_dup(m_engine->get_margo_instance(), m_addr, &new_addr);
    // TODO throw an exception if the call fails
    if(ret != HG_SUCCESS) return HG_ADDR_NULL;
    return new_addr;
}

}

