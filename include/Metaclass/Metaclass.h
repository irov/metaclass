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
		template<class T>
		Metaclass & addProperty( const std::string & _name, const T & _default, const std::string & _label, const std::string & _doc )
		{
			return *this;
		}

	public:
		template<class T, class Get, class Set>
		Metaclass & bindMember( const std::string & _name, Get _get, Set _set )
		{
			BaseGet * getter = makePropertyGet<T>( [_get]( const T * _metaclass ){ return (_metaclass->*_get)(); } );
			BaseSet * setter = makePropertySet<T>( [_set]( T * _metaclass, const auto & _value ){ (_metaclass->*_set)(_value); } );

			this->Metaclass::addGetset( _name, getter, setter );

			return *this;
		}

		template<class T, class Get, class Set>
		Metaclass & bindProperty( const std::string & _name, Get _get, Set _set )
		{
			BaseGet * getter = makePropertyGet<T>( _get );
			BaseSet * setter = makePropertySet<T>( _set );

			this->Metaclass::addGetset( _name, getter, setter );

			return *this;
		}

	public:
		bool writeMember( const std::string & _name, const void * _base, MetastreamGet & _stream ) const;
		bool readMember( const std::string & _name, void * _base, MetastreamSet & _stream ) const;

	protected:
		std::string m_name;
		Metaclass * m_base;

		struct Property
		{
			BaseGet * getter;
			BaseSet * setter;
		};

		typedef std::map<std::string, Property> TMapProperties;
		TMapProperties m_properties;

	protected:
		bool addGetset( const std::string & _name, BaseGet * _getter, BaseSet * _setter );
	};
}