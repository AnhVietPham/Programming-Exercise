package shape;

public class DrawingCircle implements DrawingShape {
    @Override
    public void draw(Shape s) {
        Circle circle = (Circle) s;
        System.out.println("This is Circle");
        System.out.println("X = " + circle.getX());
        System.out.println("Y = " + circle.getY());
        System.out.println("Radius = " + circle.getRadius());
    }
}
