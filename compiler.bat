@echo off
REM ============================================================
REM  Mini-projet Tris — compilation Windows (une seule commande)
REM  Double-cliquer sur ce fichier, OU taper : compiler.bat
REM ============================================================
setlocal EnableExtensions
cd /d "%~dp0"

echo.
echo === Compilation du benchmark ===
echo.

REM Chercher gcc dans le PATH, sinon chemins MSYS2 / MinGW courants
where gcc >nul 2>&1
if errorlevel 1 (
  if exist "C:\msys64\ucrt64\bin\gcc.exe" set "PATH=C:\msys64\ucrt64\bin;%PATH%"
  if exist "C:\msys64\mingw64\bin\gcc.exe" set "PATH=C:\msys64\mingw64\bin;%PATH%"
  if exist "C:\mingw64\bin\gcc.exe" set "PATH=C:\mingw64\bin;%PATH%"
  if exist "C:\MinGW\bin\gcc.exe" set "PATH=C:\MinGW\bin;%PATH%"
)

where gcc >nul 2>&1
if errorlevel 1 (
  echo [ERREUR] gcc introuvable.
  echo Installez MSYS2/MinGW ou ajoutez gcc au PATH.
  echo.
  pause
  exit /b 1
)

if not exist "bin" mkdir "bin"

set "CFLAGS=-O2 -Wall -Wextra -std=c11"
set "INC=-Isource\common -Isource\insertion -Isource\quick -Isource\merge -Isource\heap -Isource\counting -Isource\bucket -Isource\bubble -Isource\selection"

gcc %CFLAGS% %INC% ^
  source\common\utils.c ^
  source\insertion\insertion_sort.c ^
  source\quick\quick_sort.c ^
  source\merge\merge_sort.c ^
  source\heap\heap_sort.c ^
  source\counting\counting_sort.c ^
  source\bucket\bucket_sort.c ^
  source\bubble\bubble_sort.c ^
  source\selection\selection_sort.c ^
  source\benchmark.c ^
  -o bin\benchmark.exe

if errorlevel 1 (
  echo.
  echo [ERREUR] Echec de la compilation.
  pause
  exit /b 1
)

echo.
echo [OK] Executable : bin\benchmark.exe
echo.
echo Commandes utiles :
echo   bin\benchmark.exe
echo       -^> tableau des temps dans le terminal
echo.
echo   bin\benchmark.exe ^> visualisation\csv\resultats.csv
echo       -^> meme chose + sauvegarde CSV
echo.
echo Ou simplement :  run.bat
echo.
endlocal
