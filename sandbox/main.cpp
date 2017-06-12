#	include "Metaclass/Metaclass.h"

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

void main()
{
	Metaclass::Metaclass<Test> * MetaTest = new Metaclass::Metaclass<Test>( "Test" );
	MetaTest->addMember( "a", &Test::getA, &Test::setA );
	MetaTest->addMember( "b", &Test::getB, &Test::setB );
}