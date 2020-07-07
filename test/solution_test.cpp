#define BOOST_TEST_MODULE solution_test
#include <boost/test/included/unit_test.hpp>

#include "solution.hpp"

BOOST_AUTO_TEST_SUITE(solution_suite)

BOOST_AUTO_TEST_CASE( case_my )
{
  BOOST_CHECK(solution("") == "");
  BOOST_CHECK(solution("abcdefghijklmnopqrstuvwxyz") == "Infinite");
  BOOST_CHECK(solution("}a]b]c)start((a)){ghj(dfg)}(c[b[a{stop]") == "start((a)){ghj(dfg)}");
  BOOST_CHECK(solution("}a]b]c)s((a)){ghj(dfg)}](c[b[a{stop") == "(c[b[a{stop}a]b]c)s((a)){ghj(dfg)}");

  const std::string sIn{"}a]b]c)start((a)){ghj(dfg)}(c[b[a{ghj"};
  const std::string sOut = solution(sIn);

  BOOST_CHECK_MESSAGE(sOut == "Infinite", "Output is: " + sOut);
}

BOOST_AUTO_TEST_CASE(case_original )
{
    BOOST_CHECK(solution("sh(dh)}") == "sh(dh)");
    BOOST_CHECK(solution("]h({hdb}b)[") == "Infinite");
    BOOST_CHECK(solution("}](){") == "(){}");
}

BOOST_AUTO_TEST_SUITE_END()
