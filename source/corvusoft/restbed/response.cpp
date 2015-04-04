/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/restbed/response.h"
#include "corvusoft/restbed/detail/response_impl.h"

//External Includes

//System Namespaces
using std::string;
using std::function;
using std::multimap;

//Project Namespaces
using restbed::detail::ResponseImpl;

//External Namespaces
using framework::Bytes;

namespace restbed
{
    Response::Response( void ) : m_pimpl( new ResponseImpl )
    {
        return;
    }
    
    Response::Response( const Response& original ) : m_pimpl( new ResponseImpl( *original.m_pimpl ) )
    {
        return;
    }
    
    Response::Response( const ResponseImpl& implementation ) : m_pimpl( new ResponseImpl( implementation ) )
    {
        return;
    }
    
    Response::~Response( void )
    {
        return;
    }
    
    Bytes Response::get_body( void ) const
    {
        return m_pimpl->get_body( );
    }
    
    double Response::get_version( void ) const
    {
        return m_pimpl->get_version( );
    }
    
    int Response::get_status_code( void ) const
    {
        return m_pimpl->get_status_code( );
    }

    string Response::get_status_message( void ) const
    {
        return m_pimpl->get_status_message( );
    }
    
    string Response::get_header( const string& name ) const
    {
        return m_pimpl->get_header( name );
    }
    
    multimap< string, string > Response::get_headers( void ) const
    {
        return m_pimpl->get_headers( );
    }

    multimap< string, string > Response::get_headers( const string& name ) const
    {
        return m_pimpl->get_headers( name );
    }

    void Response::set_body( const string& value )
    {
        m_pimpl->set_body( value );
    }

    void Response::set_body( const Bytes& value )
    {
        m_pimpl->set_body( value );
    }

    void Response::set_body( const function< Bytes ( void ) >& value )
    {
        m_pimpl->set_body_callback( value );
    }
    
    void Response::set_version( const double value )
    {
        m_pimpl->set_version( value );
    }
    
    void Response::set_status_code( const int value )
    {
        m_pimpl->set_status_code( value );
    }
    
    void Response::set_status_message( const string& value )
    {
        m_pimpl->set_status_message( value );
    }
    
    void Response::set_header( const string& name, const string& value )
    {
        m_pimpl->set_header( name, value );
    }
    
    void Response::set_headers( const multimap< string, string >& values )
    {
        m_pimpl->set_headers( values );
    }
    
    Response& Response::operator =( const Response& value )
    {
        *m_pimpl = *value.m_pimpl;
        
        return *this;
    }
    
    bool Response::operator <( const Response& value ) const
    {
        return *m_pimpl < *value.m_pimpl;
    }
    
    bool Response::operator >( const Response& value ) const
    {
        return *m_pimpl > *value.m_pimpl;
    }
    
    bool Response::operator ==( const Response& value ) const
    {
        return *m_pimpl == *value.m_pimpl;
    }
    
    bool Response::operator !=( const Response& value ) const
    {
        return *m_pimpl != *value.m_pimpl;
    }
}
