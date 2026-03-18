<div align = "center">
  <h1>Clove - Physics Engine</h1>
</div>

<h2>Goal</h2>
<ul>
  <li>Simulate Hookes Law Accuractely</li>
  <li>Optimise code to create and efficient physics engine which doesn't drain computer resources</li>
  <li>The physics engine will be cross platform (Usable on Windows and Linux)</li>
</ul>

---
<h2>Tech Stack</h2>
<h3>Frontend</h3>
<ul>
  <li><b>OpenGL -</b> Used for rendering the GUI</li>
  <li><b>GLFW -</b> Used for creating and managing the GUI window</li>
</ul>

<h3>Backend</h3>
<ul>
  <li><b>GLAD -</b> Provides function pointers for OpenGL at runtime</li>
</ul>

<h3>Languages</h3>
<ul>
  <li><b>C++ -</b> Main language used for the majority of the program for it's versatility and speed</li>
  <li><b>GLSL -</b> Used for writing shaders in OpenGL</li>
</ul>

---
<h2>Controls</h2>
<h3>Mouse</h3>
<ul>
  <li><b>Left Mouse Click -</b> Spawn Box</li>
  <li><b>Middle Mouse Click -</b> Delete All Spawned Boxes</li>
</ul>

<h3>Keyboard</h3>
<ul>
  <li><b>Enter Key -</b> Toggle Light/Dark Mode</li>
  <li><b>F4 Key -</b> Close window shortcut</li>
</ul>

---
<h2>Installation</h2>
<p> If you are running the source code from VS2022, you will need to have glfw installed via vcpkg.</p>

<p> It is recommended GLFW is installed through this method and not with the website's bin files as testing has shown that the bin files cause instability with the physics engine.</p>

<a href="https://avanmonkey.github.io/Clove/">Documentation is available Here</a>

<a href="https://github.com/AvanMonkey/Clove/releases/download/Pre-Submission/Clove.v1.0.0.zip">Download the ZIP file here</a>
