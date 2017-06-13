#	pragma once

#	include "Metaclass/BaseGet.h"
#	include "Metaclass/BaseSet.h"
#	include "Metaclass/PropertyGet.h"
#	include "Metaclass/PropertySet.h"
#	include "Metaclass/MetastreamGet.h"
#	include "Metaclass/MetastreamSet.h"

#	include <string>
#	include <map>

namespace Metaclass
{
	class Metaclass
	{
	public:
		Metaclass( const std::string & _name, Metaclass * _base = nullptr );
		~Metaclass();

	public:
		template<class C, class T>
		Metaclass & addMember( const std::string & _name, T( C::*_get )() const, void (C::*_set)(T) )
		{
			BaseGet * getter = makePropertyGet<C>( [_get]( const C * _metaclass ){ return (_metaclass->*_get)(); } );
			BaseSet * setter = makePropertySet<C>( [_set]( C * _metaclass, const T & _value ){ (_metaclass->*_set)(_value); } );

			this->addGetset( _name, getter, setter );

			return *this;
		}

		template<class T, class Get, class Set>
		Metaclass & addProperty( const std::string & _name, Get _get, Set _set )
		{
			BaseGet * getter = makePropertyGet<T>( _get );
			BaseSet * setter = makePropertySet<T>( _set );

			this->addGetset( _name, getter, setter );

			return *this;
		}

	public:
		bool writeMember( const std::string & _name, const void * _base, MetastreamGet & _stream ) const;
		bool readMember( const std::string & _name, void * _base, MetastreamSet & _stream ) const;

	public:
		bool writeClass( const void * _base, MetastreamGet & _stream ) const;

	protected:
		std::string m_name;
		Metaclass * m_base;

		struct PropertyDesc
		{
			BaseGet * getter;
			BaseSet * setter;
		};

		typedef std::map<std::string, PropertyDesc> TMapProperties;
		TMapProperties m_properties;

	protected:
		bool addGetset( const std::string & _name, BaseGet * _getter, BaseSet * _setter );
	};
}