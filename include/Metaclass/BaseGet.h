#	pragma once

#	include "Metaclass/MetastreamGet.h"

namespace Metaclass
{
	class BaseGet
	{
	public:
		virtual void get( const void * _base, MetastreamGet & _stream ) const = 0;
	};
}