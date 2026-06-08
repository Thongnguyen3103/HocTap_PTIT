import sys
import platform

# Đảm bảo mã hóa UTF-8 khi in trên Windows
if sys.platform == "win32":
    sys.stdout.reconfigure(encoding='utf-8')

print("=" * 50)
print("XIN CHÀO! MÔI TRƯỜNG ANACONDA CỦA BẠN ĐÃ SẴN SÀNG!")
print("=" * 50)
print(f"Phiên bản Python: {sys.version}")
print(f"Hệ điều hành: {platform.system()} {platform.release()} ({platform.architecture()[0]})")
print(f"Thư mục chạy Python: {sys.executable}")
print("=" * 50)

try:
    import numpy as np
    print("Numpy: Đã được cài đặt (Version:", np.__version__, ")")
except ImportError:
    print("Numpy: Chưa cài đặt")

try:
    import pandas as pd
    print("Pandas: Đã được cài đặt (Version:", pd.__version__, ")")
except ImportError:
    print("Pandas: Chưa cài đặt")

try:
    import matplotlib as mpl
    print("Matplotlib: Đã được cài đặt (Version:", mpl.__version__, ")")
except ImportError:
    print("Matplotlib: Chưa cài đặt")

print("=" * 50)
