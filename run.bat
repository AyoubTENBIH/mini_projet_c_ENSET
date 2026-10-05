@echo off
REM ============================================================
REM  Lance le benchmark (compile d'abord si besoin)
REM ============================================================
setlocal
cd /d "%~dp0"

if not exist "bin\benchmark.exe" (
  echo Executable absent — compilation...
  call compiler.bat
  if errorlevel 1 exit /b 1
)

echo.
echo === Execution du benchmark ===
echo (tableau a l'ecran — duree : quelques dizaines de secondes)
echo.
bin\benchmark.exe
echo.
pause
endlocal
