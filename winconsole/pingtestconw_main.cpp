//#include <AbsoluteProtection/Sock/Icmp/cping.h>
#include <AbsoluteProtection/Sock/Icmp/cpingdll.h>

int
main()
{
	{
		WORD wVersionRequested = MAKEWORD(2, 2);
		WSADATA wsa;
		int err = WSAStartup(wVersionRequested, &wsa);
	}

	{
		AbsoluteProtection::sock::icmp::CPing cp;
		BOOL ret = FALSE;
		//ret = cp.Ping(5, "localhost");
		//ret = cp.Ping(5, "SIM101");
		//ret = cp.Ping(5, "TANAKA-PC");
		//ret = cp.Ping(5, "RV_GTune-PC");
		//ret = cp.Ping(5, "");
		ret = cp.Ping(5, "192.168.0.72");
	}

	{
		WSACleanup();

	}
	return 0;
}
