@echo off
cd /d "%~dp0"
"..\..\.venv\Scripts\python.exe" "grade_tracker_web.py" --port 8899
pause
