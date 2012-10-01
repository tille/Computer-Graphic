package mygame; 

import com.jme3.app.SimpleApplication;
import com.jme3.light.DirectionalLight;
import com.jme3.material.Material;
import com.jme3.math.ColorRGBA;
import com.jme3.math.Vector3f;
import com.jme3.scene.Geometry;
import com.jme3.scene.shape.Sphere;
import com.jme3.texture.Texture;
import com.jme3.util.TangentBinormalGenerator;
 
public class Main extends SimpleApplication {
	public static void main(String[] args) {
		Main app = new Main();
		app.start();
	}
 
	@Override
	public void simpleInitApp() {
		Sphere rock = new Sphere(32,32, 1f);
		Geometry shiny_rock2 = new Geometry("Shiny rock", rock);
		rock.setTextureMode(Sphere.TextureMode.Projected); // better quality on spheres
		TangentBinormalGenerator.generate(rock);           // for lighting effect
		Material mat_lit = new Material(assetManager, "Common/MatDefs/Light/Lighting.j3md");
		mat_lit.setTexture("DiffuseMap", assetManager.loadTexture("Textures/Terrain/Pond/Pond.jpg"));
		mat_lit.setTexture("NormalMap", assetManager.loadTexture("Textures/Terrain/Pond/Pond_normal.png"));
		mat_lit.setBoolean("UseMaterialColors",true);    
		mat_lit.setColor("Specular",ColorRGBA.White);
		mat_lit.setColor("Diffuse",ColorRGBA.Red);
		mat_lit.setFloat("Shininess", 5f); // [1,128]    
		shiny_rock2.setMaterial(mat_lit);
		shiny_rock2.setLocalTranslation(-2,2,-2); // Move it a bit
		shiny_rock2.rotate(1.6f, 0, 0);          // Rotate it a bit
		rootNode.attachChild(shiny_rock2);
    
        Sphere rock2 = new Sphere(30,30, 1f);
		Geometry shiny_rock = new Geometry("Shiny rock", rock2);
		rock.setTextureMode(Sphere.TextureMode.Projected); // better quality on spheres
		TangentBinormalGenerator.generate(rock2);           // for lighting effect
		mat_lit = new Material(assetManager, "Common/MatDefs/Light/Lighting.j3md");
		mat_lit.setTexture("DiffuseMap", assetManager.loadTexture("Textures/Terrain/Pond/Pond.jpg"));
		mat_lit.setTexture("NormalMap", assetManager.loadTexture("Textures/Terrain/Pond/Pond_normal.png"));
		mat_lit.setBoolean("UseMaterialColors",true);    
		mat_lit.setColor("Specular",ColorRGBA.White);
		mat_lit.setColor("Diffuse",ColorRGBA.Blue);
		mat_lit.setFloat("Shininess", 5f); // [1,128]    
		shiny_rock.setMaterial(mat_lit);
		shiny_rock.setLocalTranslation(0,2,-2); // Move it a bit
		shiny_rock.rotate(1.6f, 0, 0);          // Rotate it a bit
		rootNode.attachChild(shiny_rock);
    
        Sphere rock3 = new Sphere(30,30, 1f);
		Geometry shiny_rock3 = new Geometry("Shiny rock", rock3);
		rock3.setTextureMode(Sphere.TextureMode.Projected); // better quality on spheres
		TangentBinormalGenerator.generate(rock3);           // for lighting effect
		mat_lit = new Material(assetManager, "Common/MatDefs/Light/Lighting.j3md");
		mat_lit.setTexture("DiffuseMap", assetManager.loadTexture("Textures/Terrain/Pond/Pond.jpg"));
		mat_lit.setTexture("NormalMap", assetManager.loadTexture("Textures/Terrain/Pond/Pond_normal.png"));
		mat_lit.setBoolean("UseMaterialColors",true);    
		mat_lit.setColor("Specular",ColorRGBA.White);
		mat_lit.setColor("Diffuse",ColorRGBA.Green);
		mat_lit.setFloat("Shininess", 5f); // [1,128]    
		shiny_rock3.setMaterial(mat_lit);
		shiny_rock3.setLocalTranslation(2,2,-2); // Move it a bit
		shiny_rock3.rotate(1.6f, 0, 0);          // Rotate it a bit
		rootNode.attachChild(shiny_rock3);

		DirectionalLight sun = new DirectionalLight();
		sun.setDirection(new Vector3f(1,0,-2).normalizeLocal());
		sun.setColor(ColorRGBA.White);
		rootNode.addLight(sun);
	}
}