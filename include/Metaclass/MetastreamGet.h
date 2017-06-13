#	pragma once

#	include <stdint.h>
#	include <string>

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

void operator << ( Metaclass::MetastreamGet &_stream, bool _value );
void operator << ( Metaclass::MetastreamGet &_stream, int8_t _value );
void operator << ( Metaclass::MetastreamGet &_stream, int16_t _value );
void operator << ( Metaclass::MetastreamGet &_stream, int32_t _value );
void operator << ( Metaclass::MetastreamGet &_stream, int64_t _value );
void operator << ( Metaclass::MetastreamGet &_stream, uint8_t _value );
void operator << ( Metaclass::MetastreamGet &_stream, uint16_t _value );
void operator << ( Metaclass::MetastreamGet &_stream, uint32_t _value );
void operator << ( Metaclass::MetastreamGet &_stream, uint64_t _value );
void operator << ( Metaclass::MetastreamGet &_stream, float _value );
void operator << ( Metaclass::MetastreamGet &_stream, double _value );
void operator << ( Metaclass::MetastreamGet &_stream, const std::string & _value );
