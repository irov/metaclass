#	include "Metaclass/MetastreamGet.h"

//////////////////////////////////////////////////////////////////////////
template<class T>
static inline void writePOD( Metaclass::MetastreamGet & _stream, T _value )
{
	_stream.write( &_value, sizeof( T ) );
}
//////////////////////////////////////////////////////////////////////////
void operator << ( Metaclass::MetastreamGet & _stream, bool _value )
{
	writePOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator << ( Metaclass::MetastreamGet & _stream, int8_t _value )
{
	writePOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator << ( Metaclass::MetastreamGet & _stream, int16_t _value )
{
	writePOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator << ( Metaclass::MetastreamGet & _stream, int32_t _value )
{
	writePOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator << ( Metaclass::MetastreamGet & _stream, int64_t _value )
{
	writePOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator << ( Metaclass::MetastreamGet & _stream, uint8_t _value )
{
	writePOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator << ( Metaclass::MetastreamGet & _stream, uint16_t _value )
{
	writePOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator << ( Metaclass::MetastreamGet & _stream, uint32_t _value )
{
	writePOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator << ( Metaclass::MetastreamGet & _stream, uint64_t _value )
{
	writePOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator << ( Metaclass::MetastreamGet & _stream, float _value )
{
	writePOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator << ( Metaclass::MetastreamGet & _stream, double _value )
{
	writePOD( _stream, _value );
}
//////////////////////////////////////////////////////////////////////////
void operator << ( Metaclass::MetastreamGet & _stream, const std::string & _value )
{
	uint32_t string_size = _value.size();
	_stream << string_size;

	const char * string_data = _value.c_str();
	_stream.write( string_data, string_size );
}
//////////////////////////////////////////////////////////////////////////
