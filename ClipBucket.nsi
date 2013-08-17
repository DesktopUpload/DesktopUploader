/*---------------------------------------------------------------------------
$Id: ClipBucket.nsi 483 2010-07-03 11:31:28Z fwhite $
---------------------------------------------------------------------------*/

!include "Release\Product.nsh"
!define VER_BRANCH "${VER_MAJOR}.x"

;Version Info
VIProductVersion "${PRODUCT_VERSION_STRICT}"
	
VIAddVersionKey "ProductName" 		"${CUSTOM_PRODUCT_NAME}"
VIAddVersionKey "FileDescription" 	"${INTALLER_NAME}"
VIAddVersionKey "InternalName" 		"${PRODUCT_NAME}"
VIAddVersionKey "OriginalFilename" 	"${CUSTOM_EXE_NAME}-setup.exe"
VIAddVersionKey "CompanyName" 		"${PRODUCT_COMPANYNAME}"
VIAddVersionKey "LegalCopyright"        "${PRODUCT_COPYRIGHT}"
VIAddVersionKey "ProductVersion" 	"${PRODUCT_VERSION}"
VIAddVersionKey "FileVersion" 		"${PRODUCT_VERSION_STRICT}"
;Custom values, need localization:
VIAddVersionKey "Original Developer"	"${PRODUCT_ORIGINAL_DEVELOPER}"
VIAddVersionKey "Project Manager"	"${PRODUCT_PROJECT_MANAGER}"
VIAddVersionKey "Bug Tracker"	        "${PRODUCT_BUG_TRACKER}"
VIAddVersionKey "Website"	        "${PRODUCT_SITE_URL}"

!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\${CUSTOM_EXE_NAME}.exe ${VER_BRANCH}"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${CUSTOM_PRODUCT_NAME} ${VER_BRANCH}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"
!define PRODUCT_UNINST_ROOT "Software\Microsoft\Windows\CurrentVersion\Uninstall\"

SetCompressor /SOLID lzma

!include "MUI2.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "Custom\Icon-install.ico"
!define MUI_UNICON "Custom\Icon-uninstall.ico"

; Install page settings
!define MUI_WELCOMEPAGE_TITLE_3LINES
!define MUI_FINISHPAGE_TITLE_3LINES

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
!define MUI_LICENSEPAGE_CHECKBOX
!insertmacro MUI_PAGE_LICENSE "Custom\EULA"
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!define MUI_FINISHPAGE_RUN "$INSTDIR\${CUSTOM_EXE_NAME}.exe"
!define MUI_FINISHPAGE_LINK "Visit ${CUSTOM_SITE_NAME}" ;Must be localized
!define MUI_FINISHPAGE_LINK_LOCATION ${CUSTOM_SITE_URL}
!define MUI_FINISHPAGE_RUN_TEXT "Run ${CUSTOM_PRODUCT_NAME}" ;Must be localized
!insertmacro MUI_PAGE_FINISH

; Uninstall page settings
!define MUI_WELCOMEPAGE_TITLE_3LINES
!define MUI_FINISHPAGE_TITLE_3LINES

; Uninstaller pages
!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

; Language files
!insertmacro MUI_LANGUAGE "English"

; MUI end ------
!define TXT_TITLE "${CUSTOM_PRODUCT_NAME} ${PRODUCT_VERSION} (Build: ${VER_BUILD})" ;Must be localized

Name "${TXT_TITLE}"
BrandingText /TRIMRIGHT "${TXT_TITLE}"
OutFile "${CUSTOM_EXE_NAME}-setup.exe"
InstallDir "$PROGRAMFILES\${CUSTOM_PRODUCT_NAME}"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails nevershow
ShowUnInstDetails nevershow

RequestExecutionLevel admin

Section -CleanUp ;Remove garbage from previous versions or bugs
  ;Delete "$PROGRAMFILES\${CUSTOM_PRODUCT_NAME}\*.*" ;Delete files of pre-230 builds
  Delete "$PROGRAMFILES\${CUSTOM_PRODUCT_NAME}\*.svn" ;Delete *.svn directories
  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_ROOT}\${CUSTOM_PRODUCT_NAME}" ;Delete key of pre-230 builds
  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_ROOT}\ClipBucket" ;Delete key of pre-230 demo builds
  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_ROOT}\${CUSTOM_EXE_NAME}" ;Delete key created by bug in 185..216 builds
  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "Software\Microsoft\Windows\CurrentVersion\App Paths\${CUSTOM_EXE_NAME}.exe" ;Delete key of pre-230 builds
SectionEnd

Section "MainSection" SEC01
  SetShellVarContext all

  SetOutPath "$INSTDIR"
  SetOverwrite on
    File "Release\${CUSTOM_EXE_NAME}.exe"
    File "InstallFiles\*.*"
    File /r /x ".svn" "InstallFiles\FFmpeg.vhooks"
    
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
    File "InstallFiles\ffpresets\*.*"
  SetOverwrite on
  
  SetOutPath "$INSTDIR"
    CreateShortCut "$SMPROGRAMS\${CUSTOM_PRODUCT_NAME}.lnk" "$INSTDIR\${CUSTOM_EXE_NAME}.exe"
    CreateShortCut "$DESKTOP\${CUSTOM_PRODUCT_NAME}.lnk" "$INSTDIR\${CUSTOM_EXE_NAME}.exe"
  
  Exec '"$INSTDIR\${CUSTOM_EXE_NAME}.exe" -reg'
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"

  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\${CUSTOM_EXE_NAME}.exe"
    WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
    WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "QuietUninstallString" '"$INSTDIR\uninst.exe" /S'
    
    WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "InstallLocation" "$INSTDIR"
    WriteRegDWORD ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "VersionMajor" ${VER_MAJOR}
    WriteRegDWORD ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "VersionMinor" ${VER_MINOR}
    WriteRegDWORD ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "NoModify" 1
    WriteRegDWORD ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "NoRepair" 1
    
    WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName"    "${CUSTOM_PRODUCT_NAME} ${PRODUCT_VERSION}"
    WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon"    "$INSTDIR\${CUSTOM_EXE_NAME}.exe"
    WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION_STRICT}"
    WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout"   "${PRODUCT_SITE_URL}"
    WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Comments"       "${PRODUCT_SITE_NAME}"
    WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Contact"        "${PRODUCT_CONTACT_URL}"
    WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "HelpLink"       "${PRODUCT_SUPPORT_URL}"
    WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher"      "${PRODUCT_SITE_NAME}"
    WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLUpdateInfo"  "${PRODUCT_SITE_URL}"
SectionEnd


Section Uninstall
  SetShellVarContext all
  
  ExecWait '"$INSTDIR\${CUSTOM_EXE_NAME}.exe" -unreg'

  Delete "$INSTDIR\uninst.exe"

  Delete "$SMPROGRAMS\${CUSTOM_PRODUCT_NAME}.lnk"
  Delete "$DESKTOP\${CUSTOM_PRODUCT_NAME}.lnk"

  RMDir /r /REBOOTOK "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
SectionEnd