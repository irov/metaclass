#	pragma once

#	include "Metaclass/MetastreamSet.h"

namespace Metaclass
{
	class BaseSet
	{
	public:
		virtual void set( void * _base, MetastreamSet & _stream ) const = 0;
	};
}