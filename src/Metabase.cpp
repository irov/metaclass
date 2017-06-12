#	include "Metaclass/Metabase.h"

namespace Metaclass
{
	//////////////////////////////////////////////////////////////////////////
	Metabase::Metabase( const char * _name, Metabase * _base )
		: m_name( _name )
		, m_base( _base )
	{}
	//////////////////////////////////////////////////////////////////////////
	Metabase::~Metabase()
	{
		for( TVectorProperty::iterator
			it = m_properties.begin(),
			it_end = m_properties.end();
			it != it_end;
			++it )
		{
			Property & p = *it;

			delete p.getter;
			delete p.setter;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	bool Metabase::getProperty( const char * _name, const void * _base, MetastreamGet & _stream ) const
	{
		for( TVectorProperty::const_iterator
			it = m_properties.begin(),
			it_end = m_properties.end();
			it != it_end;
			++it )
		{
			const Property & p = *it;

			if( strcmp( p.name, _name ) != 0 )
			{
				continue;
			}

			p.getter->get( _base, _stream );

			return true;
		}

		return false;
	}
	//////////////////////////////////////////////////////////////////////////
	bool Metabase::setProperty( const char * _name, void * _base, MetastreamSet & _stream ) const
	{
		for( TVectorProperty::const_iterator
			it = m_properties.begin(),
			it_end = m_properties.end();
			it != it_end;
			++it )
		{
			const Property & p = *it;

			if( strcmp( p.name, _name ) != 0 )
			{
				continue;
			}

			p.setter->set( _base, _stream );

			return true;
		}

		return false;
	}
	//////////////////////////////////////////////////////////////////////////
	void Metabase::addProperty( const Property & _property )
	{
		m_properties.push_back( _property );
	}
}