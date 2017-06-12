#	pragma once

namespace Metaclass
{
	class MetastreamGet
	{
	public:
		virtual void write( const void * _buff, size_t _size ) = 0;
	};
}

template<class T>
void operator << ( Metaclass::MetastreamGet &_stream, const T & _value );