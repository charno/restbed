/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <set>
#include <map>
#include <string>
#include <stdexcept>

//Project Includes
#include <corvusoft/restbed/session.hpp>

//External Includes
#include <catch.hpp>


//System Namespaces
using std::set;
using std::string;
using std::bad_cast;
using std::multimap;
using std::out_of_range;
using std::invalid_argument;

//Project Namespaces
using restbed::Session;

//External Namespaces

TEST_CASE( "validate default instance values", "[session]" )
{
    const Session session( "f47ac10b-58cc-4372-a567-0e02b2c3d479" );
    
    REQUIRE( session.is_open( ) == false );
    REQUIRE( session.is_closed( ) == true );
    REQUIRE( session.get_origin( ) == "" );
    REQUIRE( session.get_destination( ) == "" );
    REQUIRE( session.get_headers( ).empty( ) );
    REQUIRE( session.get_id( ) == "f47ac10b-58cc-4372-a567-0e02b2c3d479" );
}

TEST_CASE( "confirm empty session id throws no exceptions", "[session]" )
{
    REQUIRE_NOTHROW( Session( "" ) );
}

TEST_CASE( "confirm default destructor throws no exceptions", "[session]" )
{
    auto session = new Session( "f47ac10b-58cc-4372-a567-0e02b2c3d479" );
    
    REQUIRE_NOTHROW( delete session );
}

TEST_CASE( "validate setters modify default values", "[session]" )
{
    Session session( "" );
    session.set_id( "f47ac10b-58cc-4372-a567-0e02b2c3d479" );
    REQUIRE( session.get_id( ) == "f47ac10b-58cc-4372-a567-0e02b2c3d479" );
    
    session.set_header( "Connection", "close" );
    multimap< string, string > expectation = { { "Connection", "close" } };
    REQUIRE( session.get_headers( ) == expectation );
    
    expectation =
    {
        { "Content-Type", "application/yaml" },
        { "Content-Encoding", "" }
    };
    
    session.set_headers( expectation );
    REQUIRE( session.get_headers( ) == expectation );
}

TEST_CASE( "validate session context functionality", "[session]" )
{
    Session session( "f47ac10b-58cc-4372-a567-0e02b2c3d479" );
    
    session.set( "Connection", string( "close" ) );
    const string connection = session.get( "Connection" );
    REQUIRE( connection == "close" );
    REQUIRE( session.has( "Connection" ) );
    REQUIRE( not session.has( "connection" ) );
    REQUIRE( session.keys( ) == set< string >( { "Connection" } ) );
    
    session.erase( "Connection" );
    REQUIRE( not session.has( "Connection" ) );
    
    const string keep_alive = session.get( "Connection", string( "keep-alive" ) );
    REQUIRE( keep_alive == "keep-alive" );
    
    REQUIRE( session.keys( ) == set< string >( ) );
    
    session.set( "Connection", string( "close" ) );
    session.set( "Connection", string( "keep-alive" ) );
    
    const string header = session.get( "Connection" );
    REQUIRE( header == "keep-alive" );
    
    int type = 0;
    REQUIRE_THROWS_AS( type = session.get( "Connection" ), bad_cast );
    
    session.erase( );
    REQUIRE( session.keys( ) == set< string >( ) );
    
    REQUIRE_THROWS_AS( session.get( "Connection" ), out_of_range );
}
