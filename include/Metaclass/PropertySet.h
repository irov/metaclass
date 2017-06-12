#	pragma once

#	include "Metaclass/BaseSet.h"

#	include "Metaclass/MetastreamSet.h"

#	include "Metaclass/SetterPull.h"

namespace Metaclass
{
	template<class T, class Set>
	class PropertySet
		: public BaseSet
	{
	public:
		PropertySet( Set _set )
			: m_set( _set )
		{}

	public:
		void set( void * _base, MetastreamSet & _stream ) const override
		{
			T * metaclass = static_cast<T *>(_base);

			Detail::SetterPull pull( _stream );

			m_set( metaclass, pull );
		}

	protected:
		Set m_set;
	};

	template<class T, class Set>
	BaseSet * makePropertySet( Set _set )
	{
		return new PropertySet<T, Set>( _set );
	}
}