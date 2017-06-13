#	pragma once

#	include <stdint.h>
#	include <string>

namespace Metaclass
{
	class MetastreamSet
	{
	public:
		virtual void read( void * _buff, size_t _size ) = 0;
		virtual const void * skip( size_t _size ) = 0;
	};
}

template<class T>
void operator >> ( Metaclass::MetastreamSet &_stream, T & _value );

void operator >> ( Metaclass::MetastreamSet &_stream, bool & _value );
void operator >> ( Metaclass::MetastreamSet &_stream, int8_t & _value );
void operator >> ( Metaclass::MetastreamSet &_stream, int16_t & _value );
void operator >> ( Metaclass::MetastreamSet &_stream, int32_t & _value );
void operator >> ( Metaclass::MetastreamSet &_stream, int64_t & _value );
void operator >> ( Metaclass::MetastreamSet &_stream, uint8_t & _value );
void operator >> ( Metaclass::MetastreamSet &_stream, uint16_t & _value );
void operator >> ( Metaclass::MetastreamSet &_stream, uint32_t & _value );
void operator >> ( Metaclass::MetastreamSet &_stream, uint64_t & _value );
void operator >> ( Metaclass::MetastreamSet &_stream, float & _value );
void operator >> ( Metaclass::MetastreamSet &_stream, double & _value );
void operator >> ( Metaclass::MetastreamSet &_stream, std::string & _value );