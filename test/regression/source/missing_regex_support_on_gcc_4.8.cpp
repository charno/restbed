/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <regex>

//Project Includes

//External Includes
#include <catch.hpp>


//System Namespaces

//Project Namespaces
using std::regex;

//External Namespaces

TEST_CASE( "missing regex support", "[stdlib]" )
{
    REQUIRE_NOTHROW( regex( "(abc[1234])" ) );
}
