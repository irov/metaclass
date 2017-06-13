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
			PropertyDesc & p = it->second;

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

		const PropertyDesc & p = it_found->second;

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

		const PropertyDesc & p = it_found->second;

		p.setter->set( _base, _stream );

		return true;
	}
	//////////////////////////////////////////////////////////////////////////
	bool Metaclass::writeClass( const void * _class, MetastreamGet & _stream ) const
	{
		_stream << m_name;

		if( m_base != nullptr )
		{
			_stream << true;

			m_base->writeClass( _class, _stream );
		}
		else
		{
			_stream << false;
		}

		uint32_t properties_size = (uint32_t)m_properties.size();

		_stream << properties_size;

		for( TMapProperties::const_iterator
			it = m_properties.begin(),
			it_end = m_properties.end();
			it != it_end;
			++it )
		{
			const std::string & name = it->first;

			_stream << name;

			const PropertyDesc & p = it->second;

			p.getter->get( _class, _stream );
		}

		return true;
	}
	//////////////////////////////////////////////////////////////////////////
	bool Metaclass::addGetset( const std::string & _name, BaseGet * _getter, BaseSet * _setter )
	{
		TMapProperties::iterator it_found = m_properties.find( _name );

		if( it_found != m_properties.end() )
		{
			return false;
		}

		PropertyDesc desc;

		desc.getter = _getter;
		desc.setter = _setter;

		m_properties.insert( std::make_pair( _name, desc ) );

		return true;
	}
}