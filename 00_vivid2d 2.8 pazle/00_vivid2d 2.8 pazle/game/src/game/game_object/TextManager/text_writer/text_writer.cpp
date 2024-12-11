#include "text_writer.h"

void TextWriter::OverWriting(std::string write_target, std::string entry_data)
{
	std::ofstream file(write_target);

	file << entry_data << std::endl;
}

void TextWriter::PostScript(std::string write_target, std::string entry_data)
{
	std::ofstream file(write_target,std::ios::app);
	std::string add_data(entry_data);

	file << add_data << std::endl;

}

void TextWriter::DeleteTextData(std::string delete_target)
{
	std::ofstream file(delete_target);

	file << "\0";
}
