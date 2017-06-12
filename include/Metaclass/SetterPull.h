#	pragma once

namespace Metaclass
{
	namespace Detail
	{
		class SetterPull
		{
		public:
			SetterPull( MetastreamSet & _stream )
				: m_stream( _stream )
			{}

		public:
			template<class T>
			operator T () const
			{
				T value;
				m_stream >> value;

				return value;
			}

		protected:
			MetastreamSet & m_stream;

		private:
			SetterPull & operator = ( const SetterPull & );
		};
	}
}