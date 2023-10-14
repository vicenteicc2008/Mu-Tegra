#include <Library/BaseLib.h>
#include <Library/PlatformMemoryMapLib.h>

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    //
    // Name, Address, Length, HobOption,
    // ResourceAttribute, ArmAttributes,
    // ResourceType, MemoryType
    //

    // DDR Regions
    {"RAM Partition", 0x80000000, 0x00108000, AddMem,
     EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     EfiConventionalMemory, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},

    {"UEFI FD", 0x80108000, 0x00200000, AddMem,
     EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     EfiBootServicesData, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},

    {"UEFI Stack", 0x80308000, 0x00040000, AddMem,
     EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     EfiBootServicesData, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},

    {"DXE Heap", 0x80348000, 0x04500000, AddMem,
     EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     EfiConventionalMemory, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},

    {"CPU Vectors", 0x84848000, 0x00001000, AddMem,
     EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     EfiBootServicesData, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},

    {"Log Buffer", 0x84849000, 0x00008000, AddMem,
     EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     EfiRuntimeServicesData, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},

    {"Info Blk", 0x84851000, 0x00001000, AddMem,
     EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     EfiRuntimeServicesData, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},

    {"RAM Partition", 0x84852000, 0x77907000, AddMem,
     EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     EfiConventionalMemory, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},

    {"Display Reserved", 0xFC159000, 0x01000000, AddMem,
     EFI_RESOURCE_MEMORY_RESERVED, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     EfiReservedMemoryType, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH},

    {"RAM Partition", 0xFD159000, 0x02D27000, AddMem,
     EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     EfiConventionalMemory, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},

    // RAM Partition Regions
    {"RAM Partition", 0xFFED8000, 0x00028000, AddMem,
     EFI_RESOURCE_SYSTEM_MEMORY, SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     EfiConventionalMemory, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK},

    // Register Regions
    {"SRAM", 0x40000000, 0x00040000, AddDev,
     EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE,
     EfiMemoryMappedIO, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE},

    {"GicR", 0x50040100, 0x00000100, AddDev,
     EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE,
     EfiMemoryMappedIO, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE},

    {"GicD", 0x50041000, 0x00001000, AddDev,
     EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE,
     EfiMemoryMappedIO, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE},

    // NOTE: Not Sure about the Name of this Region
    {"Timer", 0x60005000, 0x00003000, AddDev,
     EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE,
     EfiMemoryMappedIO, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE},

    {"GPIO", 0x6000D000, 0x00001000, AddDev,
     EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE,
     EfiMemoryMappedIO, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE},

    // NOTE: Not Sure about the Name of this Region
    {"Mux Registers", 0x70003000, 0x00001000, AddDev,
     EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE,
     EfiMemoryMappedIO, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE},

    // NOTE: Not Sure about the Name of this Region
    {"MMC", 0x78000000, 0x00001000, AddDev,
     EFI_RESOURCE_MEMORY_MAPPED_IO, EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE,
     EfiMemoryMappedIO, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE},

    // Terminator for MMU
    {"Terminator", 0, 0, 0, 0, 0, 0, 0}};

ARM_MEMORY_REGION_DESCRIPTOR_EX *GetPlatformMemoryMap()
{
    return gDeviceMemoryDescriptorEx;
}