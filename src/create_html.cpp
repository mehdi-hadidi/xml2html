#include "create_html.hpp"

// maybe we can use std::move here for achieving better performance
CreateHtml::CreateHtml(std::vector<Data>& data , const std::string& filename) : m_data(data) , m_filename(filename) {}
void CreateHtml::create()
{
    std::string htmlFileName = m_filename.substr(0 , m_filename.find_last_of("."));

    std::ofstream index_file(htmlFileName.append(".html"));

	index_file << HTML_OPEN << std::endl;
	index_file << BODY_OPEN << std::endl;
	index_file << TABLE_OPEN << std::endl;

	index_file << THEAD_OPEN  << std::endl;
	index_file << TR_OPEN  << std::endl;
	index_file <<  TH_OPEN << "TITLE"  << TH_CLOSE << std::endl;
	index_file <<  TH_OPEN << "ARTIST"  << TH_CLOSE << std::endl;
	index_file <<  TH_OPEN << "COMPANY"  << TH_CLOSE << std::endl;
	index_file <<  TH_OPEN << "COUNTRY"  << TH_CLOSE << std::endl;
	index_file <<  TH_OPEN << "PRICE"  << TH_CLOSE << std::endl;
	index_file <<  TH_OPEN << "YEAR"  << TH_CLOSE << std::endl;

	index_file << TR_CLOSE  << std::endl;
	index_file << THEAD_CLOSE << std::endl;


	for(const Data& cd : m_data)
	{
		index_file << TR_OPEN << std::endl;
		index_file << TD_OPEN << cd.getTitle()  << TD_CLOSE << std::endl;
		index_file << TD_OPEN << cd.getArtist()  << TD_CLOSE << std::endl;
		index_file << TD_OPEN << cd.getCompany()  << TD_CLOSE << std::endl;
		index_file << TD_OPEN << cd.getCountry()  << TD_CLOSE << std::endl;
		index_file << TD_OPEN << cd.getPrice()  << TD_CLOSE << std::endl;
		index_file << TD_OPEN << cd.getYear()  << TD_CLOSE << std::endl;
		index_file << TR_CLOSE << std::endl;
	}

	index_file << TABLE_CLOSE << std::endl;
	index_file << BODY_CLOSE << std::endl;
	index_file << HTML_CLOSE << std::endl;

	index_file.close();
}