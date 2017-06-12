#	pragma once

#	include "Metaclass/BaseGet.h"
#	include "Metaclass/BaseSet.h"
#	include "Metaclass/MetastreamGet.h"
#	include "Metaclass/MetastreamSet.h"

#	include <vector>

namespace Metaclass
{
	class Metabase
	{
	public:
		Metabase( const char * _name, Metabase * _base );
		~Metabase();

	public:
		bool getProperty( const char * _name, const void * _base, MetastreamGet & _stream ) const;
		bool setProperty( const char * _name, void * _base, MetastreamSet & _stream ) const;

	protected:
		const char * m_name;
		Metabase * m_base;

		struct Property
		{
			const char * name;
			BaseGet * getter;
			BaseSet * setter;
		};

		typedef std::vector<Property> TVectorProperty;
		std::vector<Property> m_properties;

	protected:
		void addProperty( const Property & _property );
	};
}