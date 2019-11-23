project('joguito', 'cpp', version: '0.1')

sfml_dep = dependency('sfml-all')
threads_dep = dependency('threads')

src = ['Concurrent/Thread.cpp', 'Concurrent/ThreadedCaster.cpp', 'Concurrent/ExtraLevel.cpp','Entities/PhysicalEntity.cpp', 'Entities/TheMirrorOfHastur.cpp', 'Entities/Enemies/TheChained.cpp', 'Entities/Enemies/Caster.cpp', 'Entities/Enemies/Leaper.cpp', 'Entities/Enemies/Enemy.cpp', 'Entities/Mob.cpp', 'Entities/Players/TheUndying.cpp', 'Entities/Players/ThePenitent.cpp', 'Entities/Entity.cpp', 'Entities/Projectiles/Projectile.cpp', 'Entities/Projectiles/Spell.cpp', 'Entities/Projectiles/Bullet.cpp', 'Lists/EntityList.cpp', 'main.cpp', 'RandomValueGenerator.cpp', 'Menus/Button.cpp', 'Menus/MainMenu.cpp', 'Menus/Menu.cpp', 'Menus/PauseMenu.cpp', 'Menus/LeaderBoard.cpp', 'Menus/TextInputBox.cpp', 'Menus/LeaderBoardMenu.cpp', 'PhysicalEntityList.cpp', 'DescentIntoMadness.cpp', 'Tiles/TileManager.cpp', 'Tiles/TileVector.cpp', 'Tiles/TileMap.cpp', 'Tiles/BulletObstacle.cpp', 'Tiles/Tile.cpp', 'EventManager.cpp', 'Mementos/TheMirrorOfHasturMemento.cpp', 'Mementos/ThePenitentMemento.cpp', 'Mementos/TheUndyingMemento.cpp', 'Mementos/BulletMemento.cpp', 'Mementos/Memento.cpp', 'Mementos/SpellMemento.cpp', 'Mementos/TheChainedMemento.cpp', 'Mementos/CasterMemento.cpp', 'Mementos/LeaperMemento.cpp', 'Mementos/TileManagerMemento.cpp', 'Mementos/LevelMemento.cpp', 'GraphicsManager.cpp', 'Levels/Level.cpp', 'Levels/CavernLevel.cpp', 'Levels/TempleLevel.cpp', 'CollisionManager.cpp']


executable('joguito', src, dependencies: [sfml_dep, threads_dep])