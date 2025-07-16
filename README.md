# DefaultTemplateGem

DefaultTemplateGem is a template project for creating Gems in O3DE (Open 3D Engine). With this project, you can quickly generate a basic framework for a new O3DE runtime Gem, suitable for extending game or application functionality, without any editor features.

## Features
- The generated Gem includes only runtime features, no editor extensions.
- Cross-platform support (Windows, Linux, Mac, Android, iOS).
- Clear structure for easy secondary development and customization.

## Quick Start
1. Clone or copy this template project into your Gems directory.
2. Navigate to the project root and run the following command to create a new Gem framework:

```bash
python rename.py NewGem
```

Replace `NewGem` with your desired Gem name.

3. Continue development based on the generated directory structure.

## Directory Structure
- `Code/`: C++ source code, headers, and platform-specific implementations
- `Registry/`: Registry and configuration files
- `rename.py`: Gem renaming and initialization script
- `gem.json`: Gem metadata description file

## Dependencies
- Python 3.x (for running the rename.py script)
- O3DE engine environment

## License
See the LICENSE file for details.

---
For more help, please refer to the official O3DE documentation or the comments within this project.