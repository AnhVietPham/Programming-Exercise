package shape;

public abstract class Shape {
    protected DrawingShape drawer;

    public Shape(DrawingShape drawer) {
        this.drawer = drawer;
    }

    public abstract void draw();
}
