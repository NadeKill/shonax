// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "spammers.h"

void spammers::clan_tag()
{
	auto apply = [](const char* tag) -> void
	{
		using Fn = int(__fastcall*)(const char*, const char*);
		static auto fn = reinterpret_cast<Fn>(util::FindSignature(crypt_str("engine.dll"), crypt_str("53 56 57 8B DA 8B F9 FF 15")));

		fn(tag, tag);
	};

	static auto removed = false;

	if (!g_cfg.misc.clantag_spammer && !removed)
	{
		removed = true;
		apply(crypt_str(""));
		return;
	}

	if (g_cfg.misc.clantag_spammer)
	{
		auto nci = m_engine()->GetNetChannelInfo();

		if (!nci)
			return;

		static auto time = -1;

		auto ticks = TIME_TO_TICKS(nci->GetAvgLatency(FLOW_OUTGOING)) + (float)m_globals()->m_tickcount; //-V807
		auto intervals = 0.5f / m_globals()->m_intervalpertick;

		auto main_time = (int)(ticks / intervals) % 22;

		if (main_time != time && !m_clientstate()->iChokedCommands)
		{
			auto tag = crypt_str("");

			switch (main_time)
			{
			case 0:
				tag = crypt_str("ch4zhook "); //-V1037
				break;
			case 1:
				tag = crypt_str("h4zhook ");
				break;
			case 2:
				tag = crypt_str("4zhook ");
				break;
			case 3:
				tag = crypt_str("zhook ");
				break;
			case 4:
				tag = crypt_str("hook ");
				break;
			case 5:
				tag = crypt_str("ook ");
				break;
			case 6:
				tag = crypt_str("ok ");
				break;
			case 7:
				tag = crypt_str("k ");
				break;
			case 8:
				tag = crypt_str("");
				break;
			case 9:
				tag = crypt_str("e ");
				break;
			case 10:
				tag = crypt_str("");
				break;
			case 11:
				tag = crypt_str("c");
				break;
			case 12:
				tag = crypt_str("ch");
				break;
			case 13:
				tag = crypt_str("ch4");
				break;
			case 14:
				tag = crypt_str("ch4z");
				break;
			case 15:
				tag = crypt_str("ch4zh");
				break;
			case 16:
				tag = crypt_str("ch4zho");
				break;
			case 17:
				tag = crypt_str("ch4zhoo");
				break;
			case 18:
				tag = crypt_str("ch4zhook");
				break;
			}

			apply(tag);
			time = main_time;
		}

		removed = false;
	}
}