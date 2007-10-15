; This script creates an installer for 
; hashlib++ under windows
;--------------------------------

  ;Include Modern UI
  !include "MUI.nsh"

;--------------------------------

  ; The name of the installer
  Name "hashlib++"

  ; The file to write
  OutFile "Setup.exe"

  ; The default installation directory
  InstallDir $PROGRAMFILES\hashlib++

  ;Get installation folder from registry if available
  InstallDirRegKey HKCU "Software\hashlib++" ""

;--------------------------------

  ;Interface Settings
  !define MUI_ABORTWARNING

;--------------------------------

; Pages
  !insertmacro MUI_PAGE_LICENSE "../doc/LICENSE.TXT"
  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES
;--------------------------------

  ;Languages
  !insertmacro MUI_LANGUAGE "English"

;--------------------------------

; The stuff to install
Section "" ;No components page, name is not important

  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
  
  ; Files to install:
  ; Put hashlib++ as a static lib in this dir
  ; and name it "hl++.lib"
  File hl++.lib
  File hl_hashwrapper.h
  File hl_md5.h
  File hl_md5wrapper.h
  File hl_sha1.h
  File hl_sha1wrapper.h
  File hl_sha256.h
  File hl_sha256wrapper.h
  
  ;Store installation folder
  WriteRegStr HKCU "Software\hashlib++" "" $INSTDIR
  
  ;Create uninstaller
  WriteUninstaller "$INSTDIR\Uninstall.exe"

SectionEnd ; end the section

;--------------------------------
;Uninstaller Section

Section "Uninstall"

  Delete "$INSTDIR\Uninstall.exe"
  Delete "$INSTDIR\hl++.lib"
  Delete "$INSTDIR\hl_hashwrapper.h"
  Delete "$INSTDIR\hl_md5.h"
  Delete "$INSTDIR\hl_md5wrapper.h"
  Delete "$INSTDIR\hl_sha1.h"
  Delete "$INSTDIR\hl_sha1wrapper.h"
  Delete "$INSTDIR\hl_sha256.h"
  Delete "$INSTDIR\hl_sha256wrapper.h"

  RMDir "$INSTDIR"

  DeleteRegKey /ifempty HKCU "Software\hashlib++"

SectionEnd
