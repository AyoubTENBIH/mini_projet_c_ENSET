@echo off
REM ============================================================
REM  Compile + execute + sauve le CSV
REM ============================================================
setlocal
cd /d "%~dp0"

call compiler.bat
if errorlevel 1 exit /b 1

if not exist "visualisation\csv" mkdir "visualisation\csv"

echo.
echo === Benchmark + export CSV ===
bin\benchmark.exe > visualisation\csv\resultats.csv
if errorlevel 1 (
  echo [ERREUR] Execution echouee.
  pause
  exit /b 1
)

echo.
echo [OK] CSV : visualisation\csv\resultats.csv
echo.
pause
endlocal
