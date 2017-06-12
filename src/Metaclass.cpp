#	include "Metaclass/Metaclass.h"

namespace Metaclass
{
	//////////////////////////////////////////////////////////////////////////
	Metaclass::Metaclass( const std::string & _name, Metaclass * _base )
		: m_name( _name )
		, m_base( _base )
	{}
	//////////////////////////////////////////////////////////////////////////
	Metaclass::~Metaclass()
	{
		for( TMapProperties::iterator
			it = m_properties.begin(),
			it_end = m_properties.end();
			it != it_end;
			++it )
		{
			Property & p = it->second;

			delete p.getter;
			delete p.setter;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	bool Metaclass::writeMember( const std::string & _name, const void * _base, MetastreamGet & _stream ) const
	{
		TMapProperties::const_iterator it_found = m_properties.find( _name );

		if( it_found == m_properties.end() )
		{
			return false;
		}

		const Property & p = it_found->second;

		p.getter->get( _base, _stream );

		return true;		
	}
	//////////////////////////////////////////////////////////////////////////
	bool Metaclass::readMember( const std::string & _name, void * _base, MetastreamSet & _stream ) const
	{
		TMapProperties::const_iterator it_found = m_properties.find( _name );

		if( it_found == m_properties.end() )
		{
			return false;
		}

		const Property & p = it_found->second;

		p.setter->set( _base, _stream );

		return true;
	}
	//////////////////////////////////////////////////////////////////////////
	bool Metaclass::addGetset( const std::string & _name, BaseGet * _getter, BaseSet * _setter )
	{
		TMapProperties::iterator it_found = m_properties.find( _name );

		if( it_found == m_properties.end() )
		{
			return false;
		}

		Property & p = it_found->second;

		p.getter = _getter;
		p.setter = _setter;

		return true;
	}
}