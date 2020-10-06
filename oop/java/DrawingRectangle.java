package shape;

public class DrawingRectangle implements DrawingShape {

    public DrawingRectangle(){}

    @Override
    public void draw(Shape s) {
        Rectangle rectangle = (Rectangle) s;
        System.out.println("This is Rectangle");
        System.out.println("x = " + rectangle.getX());
        System.out.println("y = " + rectangle.getY());
        System.out.println("w = " + rectangle.getW());
        System.out.println("H = " + rectangle.getH());
    }
}
