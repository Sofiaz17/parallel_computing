import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter
import math

# Read the data from the CSV files
headers = ['block_size', 'time']
df = pd.read_csv('dataMatrix.csv', names=headers)
df_vectorized = pd.read_csv('dataMatrix_vectorized.csv', names=headers)
df_prefetched = pd.read_csv('dataMatrix_prefetched.csv', names=headers)

# Plot the data
plt.figure(figsize=(13, 8))  # Set the figure size
plt.plot(df['block_size'], df['time'], marker='o', label='Non-vectorized Data', color='c')
plt.plot(df_vectorized['block_size'], df_vectorized['time'], marker='o', label='Vectorized Data', color='y')
plt.plot(df_prefetched['block_size'], df_prefetched['time'], marker='o', label='Prefetched Data', color='r')

# Customize the plot
plt.xlabel('Block Size (logarithmic scale)')
plt.ylabel('Time (s)')
plt.title('Sequential vs prefetched vs vectorized matrix copy time')

plt.xscale('log')  # Set x-axis to a logarithmic scale

def log_format(x, pos):
    if x == 0:
        return "0"
    exponent = int(math.floor(math.log10(x)))
    mantissa = x / 10**exponent
    return f"${mantissa:.2f} \\times 10^{{{exponent}}}$"

y_formatter = FuncFormatter(log_format)
plt.gca().yaxis.set_major_formatter(y_formatter)

#plt.yscale('log')  # Set y-axis to a logarithmic scale
plt.xticks(df['block_size'], labels=df['block_size'].astype(str), rotation=45)  # Set x-axis labels
#plt.yticks(df['time'], labels=df['time'].astype(str))  # Set y-axis labels


# Add legend and grid
plt.legend()
plt.grid(True, which='both', linestyle='--', linewidth=0.5)

# Show the plot

plt.savefig("dataEx2.png")
