#	pragma once

#	include "Metaclass/BaseGet.h"

#	include "Metaclass/MetastreamGet.h"

namespace Metaclass
{
	template<class T, class Get>
	class PropertyGet
		: public BaseGet
	{
	public:
		PropertyGet( Get _get )
			: m_get( _get )
		{
		}

	public:
		void get( const void * _base, MetastreamGet & _stream ) const override
		{
			const T * metaclass = static_cast<const T *>(_base);

			_stream << m_get( metaclass );
		}

	protected:
		Get m_get;
	};

	template<class T, class Get>
	BaseGet * makePropertyGet( Get _get )
	{
		return new PropertyGet<T, Get>( _get );
	}
}