#	pragma once

namespace Metaclass
{
	class MetastreamSet
	{
	public:
		virtual void read( void * _buff, size_t _size ) = 0;
	};
}

template<class T>
void operator >> ( Metaclass::MetastreamSet &_stream, T & _value );
