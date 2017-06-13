#	include "Metaclass/MetastreamSet.h"

//////////////////////////////////////////////////////////////////////////
template<class T>
static inline void readPOD( Metaclass::MetastreamSet & _stream, T & _value )
{
	_stream.read( &_value, sizeof( T ) );
}
//////////////////////////////////////////////////////////////////////////
void operator >> ( Metaclass::MetastreamSet & _stream, bool & _value )
{
	readPOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator >> ( Metaclass::MetastreamSet & _stream, int8_t & _value )
{
	readPOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator >> ( Metaclass::MetastreamSet & _stream, int16_t & _value )
{
	readPOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator >> ( Metaclass::MetastreamSet & _stream, int32_t & _value )
{
	readPOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator >> ( Metaclass::MetastreamSet & _stream, int64_t & _value )
{
	readPOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator >> ( Metaclass::MetastreamSet & _stream, uint8_t & _value )
{
	readPOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator >> ( Metaclass::MetastreamSet & _stream, uint16_t & _value )
{
	readPOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator >> ( Metaclass::MetastreamSet & _stream, uint32_t & _value )
{
	readPOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator >> ( Metaclass::MetastreamSet & _stream, uint64_t & _value )
{
	readPOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator >> ( Metaclass::MetastreamSet & _stream, float & _value )
{
	readPOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator >> ( Metaclass::MetastreamSet & _stream, double & _value )
{
	readPOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator >> ( Metaclass::MetastreamSet & _stream, std::string & _value )
{
	uint32_t string_size;
	_stream >> string_size;

	const void * stream_data = _stream.skip( string_size );

	const char * string_data = static_cast<const char *>(stream_data);

	_value.assign( string_data, string_size );
}
//////////////////////////////////////////////////////////////////////////