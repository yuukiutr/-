#include "TextManager.h"

TextManager& TextManager::GetInstance(void)
{
	static TextManager instance;

	// TODO: return ステートメントをここに挿入します
	return instance;
}

void TextManager::Load(LOAD_ID id, std::string load_data)
{
#if DRAW_DEBUG_DATA

	printfDx("Load Start\n");

#endif

	switch (id)
	{
	case LOAD_ID::ONLY_NUMERIC:
		m_Loader.Load_OnlyNumeric(load_data);
		break;
	case LOAD_ID::ONLY_ALPHABET:
		m_Loader.Load_OnlyAlphabet(load_data);
		break;
	case LOAD_ID::ONLY_JAPANESE:
		m_Loader.Load_OnlyJapanese(load_data);
		break;
	case LOAD_ID::ALPHABET_AND_NUMERIC:
		m_Loader.Load_AlphabetAndNumeric(load_data);
		break;
	case LOAD_ID::ALL:
		m_Loader.Load_All(load_data);
		break;
	default:
		break;
	}

#if DRAW_DEBUG_DATA

	printfDx("Load Finish\n");

#endif

}

void TextManager::SaveAndCreate(SAVE_ID id, std::string save_target,std::string entry_data)
{
#if DRAW_DEBUG_DATA

	printfDx("Save Start\n");

#endif

	switch (id)
	{
	case SAVE_ID::CREATE:
		m_Writer.OverWriting(save_target, entry_data);
		break;
	case SAVE_ID::OVERWRITING:
		m_Writer.OverWriting(save_target, entry_data);
		break;
	case SAVE_ID::PS:
		m_Writer.PostScript(save_target, entry_data);
		break;
	default:
		break;
	}

#if DRAW_DEBUG_DATA

	printfDx("Save Finish\n");

#endif

}



void TextManager::Copy(COPY_ID id, std::string target_file, std::string copy_file)
{
#if DRAW_DEBUG_DATA

	printfDx("Copy Start\n");

#endif

	switch (id)
	{
	case COPY_ID::NORMAL:
		this->NormalCopy(target_file, copy_file);
		break;
	case COPY_ID::QUICK:
		this->QuickCopy(target_file, copy_file);
		break;
	case COPY_ID::CONNECT_BOTTOM:
		this->ConnectCopyDestination(target_file, copy_file);
		break;
	case COPY_ID::CONNECT_TOP:
		this->CopyDataToTheTop(target_file, copy_file);
		break;
	default:
		break;
	}

#if DRAW_DEBUG_DATA

	printfDx("Copy Finish\n");

#endif

}

std::vector<std::string> TextManager::GetLoadData(void)
{
	return m_Loader.GetLoadData();
}

void TextManager::DeleteLoadData(void)
{
	m_Loader.DeleteLoadData();
}

void TextManager::DeleteTextData(std::string target)
{
	m_Writer.DeleteTextData(target);
}

void TextManager::DeleteTextFile(std::string target)
{
#if DRAW_DEBUG_DATA

	printfDx("Delete Start\n\n");

#endif

	std::remove(target.c_str());
	std::remove("0");

#if DRAW_DEBUG_DATA

	printfDx("...\\src\\game_object\\TextManager\\TextManager.h\n");
	printfDx("TextManager::DeleteTextFile\n");
	printfDx("TextFile : ");
	printfDx(target.c_str());
	printfDx("  Delete\n");
	printfDx("\n");

#endif

#if DRAW_DEBUG_DATA

	printfDx("Delete Finish\n");

#endif

}

void TextManager::QuickCopy(std::string target_file, std::string copy_file)
{
	FILE* copy = nullptr;
	FILE* target = nullptr;

	fopen_s(&copy, copy_file.c_str(), "rb");
	fopen_s(&target, target_file.c_str(), "wb");

	std::vector<char> buffer(1024 * 1024);

	while (!feof(copy))
	{
		size_t size = fread(&buffer[0], 1, buffer.size(), copy);
		fwrite(&buffer[0], 1, size, target);
	}

	fclose(copy);
	fclose(target);

}

void TextManager::NormalCopy(std::string target_file, std::string copy_file)
{
	std::ifstream copy(copy_file, std::ios::in | std::ios::binary);
	std::ofstream target(target_file, std::ios::out | std::ios::binary);

	std::istreambuf_iterator<char> iit(copy);
	std::istreambuf_iterator<char> end;
	std::ostreambuf_iterator<char> oit(target);
	std::copy(iit, end, oit);

}

void TextManager::ConnectCopyDestination(std::string target_file, std::string copy_file)
{
	std::ifstream file(copy_file);
	std::string line = "\0";

	while (std::getline(file, line))
	{
		this->SaveAndCreate(SAVE_ID::PS, target_file, line);
	}
}

void TextManager::CopyDataToTheTop(std::string target_file, std::string copy_file)
{
	this->SaveAndCreate(SAVE_ID::CREATE, "data/tmp.txt", "");
	this->NormalCopy("data/tmp.txt", target_file);
	this->NormalCopy(target_file, copy_file);
	this->ConnectCopyDestination(target_file, "data/tmp.txt");
	this->DeleteTextFile("data/tmp.txt");
}
