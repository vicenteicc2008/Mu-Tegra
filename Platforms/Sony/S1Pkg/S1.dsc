## @file
#
#  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = S1
  PLATFORM_GUID                  = f9287658-dc58-4ee4-9606-9a3cfe9a0105
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/S1Pkg
  SUPPORTED_ARCHITECTURES        = ARM
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = S1Pkg/S1.fdf

  # 0 = T30
  # 1 = T30L
  # 2 = T33
  SOC_TYPE                       = 1

  # 0 = DDR3-L
  # 1 = LPDDR2-1066
  RAM_MODEL                      = 0

[BuildOptions.common]
  *_*_*_CC_FLAGS = -DSOC_TYPE=$(SOC_TYPE) -DRAM_MODEL=$(RAM_MODEL)

[LibraryClasses.common]
  PlatformMemoryMapLib|S1Pkg/Library/PlatformMemoryMapLib/PlatformMemoryMapLib.inf

[PcdsFixedAtBuild.common]
  # Platform-specific
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x80000000              # Starting address
  gArmTokenSpaceGuid.PcdSystemMemorySize|0x40000000              # 2GB Size

  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVendor|L"vicenteicc2008"  # Device Maintainer

  gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|0x84848000

  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0x80308000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00040000           # 256K stack

  # SmBios
  gNvidiaPkgTokenSpaceGuid.PcdSmbiosSystemVendor|"Sony"
  gNvidiaPkgTokenSpaceGuid.PcdSmbiosSystemModel|"Xperia Tablet S"
  gNvidiaPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"SGPT1211"
  gNvidiaPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"Xperia_Tablet_S_SGPT1211"
  gNvidiaPkgTokenSpaceGuid.PcdSmbiosBoardModel|"Xperia Tablet S"

  # Simple FrameBuffer
  gNvidiaPkgTokenSpaceGuid.PcdMipiFrameBufferWidth|1280
  gNvidiaPkgTokenSpaceGuid.PcdMipiFrameBufferHeight|800
  gNvidiaPkgTokenSpaceGuid.PcdMipiFrameBufferPixelBpp|32

[PcdsDynamicDefault.common]
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|1280
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|800
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|1280
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|800
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutColumn|170
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutRow|40
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutColumn|170
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutRow|40

!include Tegra30Pkg/Tegra30Pkg.dsc.inc