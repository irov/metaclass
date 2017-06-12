#	pragma once

#	include "Metaclass/Metabase.h"

#	include "Metaclass/PropertyGet.h"
#	include "Metaclass/PropertySet.h"

namespace Metaclass
{
	template<class T>
	class Metaclass
		: public Metabase
	{
	public:
		Metaclass( const char * _name, Metabase * _base = nullptr )
			: Metabase( _name, _base )
		{
		}

	public:
		template<class Get, class Set>
		Metaclass<T> * addMember( const char * _name, Get _get, Set _set )
		{
			Property p;
			p.name = _name;
			p.getter = makePropertyGet<T>( [_get]( const T * _metaclass ){ return (_metaclass->*_get)(); } );
			p.setter = makePropertySet<T>( [_set]( T * _metaclass, const auto & _value ){ (_metaclass->*_set)(_value); } );

			this->Metabase::addProperty( p );

			return this;
		}

		template<class Get, class Set>
		Metaclass<T> * addProperty( const char * _name, Get _get, Set _set )
		{
			Property p;
			p.name = _name;
			p.getter = makePropertyGet<T>( _get );
			p.setter = makePropertySet<T>( _set );

			this->Metabase::addProperty( p );

			return this;
		}
	};
}