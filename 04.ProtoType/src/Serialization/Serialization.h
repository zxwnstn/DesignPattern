#pragma once

namespace Serializations {

	struct Address
	{
		std::string street;
		std::string city;
		int suite;

	private:
		friend class boost::serialization::access;
		template<class Ar>
		void serialize(Ar& ar, const unsigned int version)
		{
			ar & street;
			ar & city;
			ar & suite;
		}
	};

	struct Contact
	{
		std::string name;
		Address* address = nullptr;

	private:
		friend class boost::serialization::access;
		template<class Ar>
		void serialize(Ar& ar, const unsigned int version)
		{
			ar & name;
			ar & address;
		}
	};

	inline void exec()
	{
		Contact c{ "naasdf", new Address{"asdf", "asdf", 10} };
		auto clone = [](const Contact& c){
		
			std::ostringstream oss;
			boost::archive::text_oarchive oa(oss);
		
			oa << c;
		
			std::istringstream iss(oss.str());
			boost::archive::text_iarchive ia(iss);
			Contact result;
			ia >> result;
		
			return result;
		};

		auto clone_v = clone(c);
	}

}