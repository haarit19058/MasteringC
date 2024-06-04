import matplotlib.pyplot as plt
import numpy as np

# Create 3D axes
fig = plt.figure()
ax = plt.axes(projection='3d')

# Generate data
x = np.linspace(-10, 10, 200)
y = np.linspace(-10, 10, 200)
x_grid, y_grid = np.meshgrid(x, y)
# z = np.abs(5 * np.sin(x_grid)) + np.abs(5 * np.cos(y_grid))

z = 2*np.sin(x_grid) + np.cos(y_grid)

# Plot surface
surf = ax.plot_surface(x_grid, y_grid,z)
ax.set_title('Sponge Design')
ax.set_zlim(-4,4)
# Change viewing angle
ax.view_init(elev=50, azim=35)  # Change the elevation to 30 degrees and azimuth to 45 degrees

plt.show()
