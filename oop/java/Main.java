package shape;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Shape> shapes = new ArrayList<>();
        DrawingRectangle drawingRectangle = new DrawingRectangle();
        DrawingCircle drawingCircle = new DrawingCircle();
        Rectangle rectangle = new Rectangle(10, 10, 10, 10, drawingRectangle);
        Rectangle rectangle1 = new Rectangle(107, 106, 106, 108, drawingRectangle);
        Circle circle = new Circle(20, 20, 30, drawingCircle);
        shapes.add(rectangle);
        shapes.add(rectangle1);
        shapes.add(circle);

        for (Shape shape : shapes) {
            shape.draw();
        }
    }
}
