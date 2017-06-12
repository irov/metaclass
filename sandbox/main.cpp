#	include "Metaclass/Metaclass.h"

#	include <vector>

class Test
{
public:
	Test()
		:m_a( 0 )
	{}

public:
	void setA( int a ) { m_a = a; }
	int getA() const { return m_a; }

	void setB( float b ) { m_b = b; }
	float getB() const { return m_b; }

protected:
	int m_a;
	float m_b;
};

void operator << ( Metaclass::MetastreamGet &_stream, int _value )
{
	_stream.write( &_value, sizeof( int ) );
}

void operator << ( Metaclass::MetastreamGet &_stream, float _value )
{
	_stream.write( &_value, sizeof( float ) );
}

void operator >> ( Metaclass::MetastreamSet &_stream, int & _value )
{
	_stream.read( &_value, sizeof( int ) );
}

void operator >> ( Metaclass::MetastreamSet &_stream, float & _value )
{
	_stream.read( &_value, sizeof( float ) );
}

class MyMetastreamGet
	: public Metaclass::MetastreamGet
{
public:
	MyMetastreamGet( std::vector<uint8_t> & _data )
		: m_data( _data )
	{}

protected:
	void write( const void * _buff, size_t _size ) override
	{
		const uint8_t * data_begin = static_cast<const uint8_t *>(_buff);
		const uint8_t * data_end = data_begin + _size;

		m_data.insert( m_data.end(), data_begin, data_end );
	}

protected:
	std::vector<uint8_t> & m_data;

private:
	MyMetastreamGet & operator = ( const MyMetastreamGet & );
};

class MyMetastreamSet
	: public Metaclass::MetastreamSet
{
public:
	MyMetastreamSet( const std::vector<uint8_t> & _data )
		: m_data( _data )
	{}

protected:
	void read( void * _buff, size_t _size ) override
	{
		const uint8_t * data_begin = m_data.data();
		const uint8_t * data_end = data_begin + _size;

		uint8_t * data_dest = static_cast<uint8_t *>(_buff);

		std::copy( data_begin, data_end, data_dest );
	}

protected:
	const std::vector<uint8_t> & m_data;

private:
	MyMetastreamSet & operator = ( const MyMetastreamSet & );
};

void main()
{
	Metaclass::Metaclass metaTest( "Test" );
	metaTest.addProperty( "a", 0, "lable a", "a - int property!" );
	metaTest.addProperty( "b", 0.f, "lable b", "b - float property!" );

	metaTest.bindMember<Test>( "a", &Test::getA, &Test::setA );
	metaTest.bindMember<Test>( "b", &Test::getB, &Test::setB );

	Test * t = new Test;

	t->setA( 13 );
	t->setB( 12.f );

	std::vector<uint8_t> buff;

	MyMetastreamGet stream_get( buff );
	metaTest.writeMember( "a", t, stream_get );

	t->setA( 1 );

	MyMetastreamSet stream_set( buff );
	metaTest.readMember( "a", t, stream_set );

	int a = t->getA();

	printf( "%d", a );
}