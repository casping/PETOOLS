// VMPackLib
#ifndef __CVIRTUALMEMORY__
#define __CVIRTUALMEMORY__


// 虚拟地址内存类
class CVirtualMemory
{

public:
	// 虚拟地址所对应的内存.
	STu8* m_BaseAddr;
	// 内存的空间大小
	STu32 m_addrlen;
	//虚拟内存地址
	DWORD m_VirtualBaseAddress;
private:
	// 还未使用的起始地址
	STu8* CurrentAddress;
public:

	CVirtualMemory();

	CVirtualMemory(DWORD VirtualAddress,
			   int len);

	~CVirtualMemory();

	// 创建一片对应虚拟地址的内存空间
	void	CreateVirtualMemory(DWORD VirtualAddress,
						  STu32 len);

	// 根据内存地址换算出虚拟线性地址
	DWORD	GetVirtualAddress(STu8* addr);

	// 根据虚拟地址计算出内存空间地址
	STu8*	GetAddrOfVirtualAddr(DWORD VirtualAddress);

	// 复制数据到虚拟内存,返回数据的起始虚拟地址.
	DWORD	WriteData(STu8* src, STu32 len);
	//复制数据到指令虚拟内存地址
	DWORD	WriteData(DWORD VirtualCode, STu8* src, STu32 len);
	// 清空内存
	void	ClearMemory();

	// 获得当前可用空间
	STu8*	GetCurrentAddr(void);
	// 获得当前可用的虚拟地质
	DWORD	GetCurrentVirtualAddress(void);
};// END CLASS DEFINITION CVirtualMemory

#endif // __CVIRTUALMEMORY__
