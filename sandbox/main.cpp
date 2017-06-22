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

    void setC( float c ) { m_c = c; }
    float getC() const { return m_c; }

protected:
	int m_a;
	float m_b;
    float m_c;
};

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
		, m_pos( 0 )
	{}

protected:
	void read( void * _buff, size_t _size ) override
	{
		const uint8_t * data_begin = m_data.data();
		const uint8_t * data_pos = data_begin + m_pos;
		const uint8_t * data_end = data_pos + _size;

		uint8_t * data_dest = static_cast<uint8_t *>(_buff);

		std::copy( data_begin, data_end, data_dest );

		m_pos += _size;
	}

	const void * skip( size_t _size ) override
	{
		const uint8_t * data_begin = m_data.data();
		const uint8_t * data_pos = data_begin + m_pos;

		m_pos += _size;
		
		return data_pos;
	}

protected:
	const std::vector<uint8_t> & m_data;
	uint32_t m_pos;

private:
	MyMetastreamSet & operator = ( const MyMetastreamSet & );
};

void main()
{
	Metaclass::Metaclass metaTest( "Test" );
	metaTest.addMember<Test>( "a", &Test::getA, &Test::setA );
	metaTest.addMember<Test>( "b", &Test::getB, &Test::setB );
    metaTest.addProperty<Test>( "c", []( const Test * _metaclass ){ return _metaclass->getC(); }, []( Test * _metaclass, float value ){ _metaclass->setC( value ); } );

	Test * t = new Test;

	t->setA( 13 );
	t->setB( 12.f );
    t->setC( 123.f );

	std::vector<uint8_t> buff;

	MyMetastreamGet stream_get( buff );
	metaTest.writeMember( "c", t, stream_get );

	t->setC( 1.f );

	MyMetastreamSet stream_set( buff );
	metaTest.readMember( "c", t, stream_set );

	float c = t->getC();


	metaTest.writeClass( t, stream_get );

	printf( "%f", c );
}