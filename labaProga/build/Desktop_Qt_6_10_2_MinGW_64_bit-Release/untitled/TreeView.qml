import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: rootWindow
    width: 900
    height: 900
    visible: true
    title: "Дерево рекурсии"

    property var rootNode: null
    property int verticalSpacing: 100
    property int horizontalSpacing: 120

    // Данные для рисования
    property var nodesPositions: []

    Flickable {
        id: flickable
        anchors.fill: parent
        contentWidth: canvas.width
        contentHeight: canvas.height
        clip: true

        Canvas {
            id: canvas
            width: 1
            height: 1

            onPaint: {
                var ctx = canvas.getContext("2d");
                ctx.clearRect(0, 0, canvas.width, canvas.height);
                if (!rootWindow.rootNode) return;

                for (var i = 0; i < nodesPositions.length; ++i) {
                    var item = nodesPositions[i];
                    var node = item.node;
                    var x = item.x;
                    var y = item.y;

                    // Рисуем узел
                    ctx.fillStyle = "#e0e0e0";
                    ctx.strokeStyle = "black";
                    ctx.lineWidth = 2;
                    ctx.beginPath();
                    ctx.arc(x, y, 30, 0, Math.PI*2);
                    ctx.fill();
                    ctx.stroke();

                    ctx.fillStyle = "black";
                    ctx.font = "14px Arial";
                    ctx.textAlign = "center";
                    ctx.textBaseline = "middle";
                    ctx.fillText("n=" + node.n, x, y-5);
                    ctx.fillText("res=" + node.result, x, y+10);
                }

                for (var i = 0; i < nodesPositions.length; ++i) {
                    var parentItem = nodesPositions[i];
                    var parentNode = parentItem.node;
                    var parentX = parentItem.x;
                    var parentY = parentItem.y;


                    for (var j = 0; j < parentNode.children.length; ++j) {
                        var childNode = parentNode.children[j];

                        var childItem = nodesPositions.find(function(p) { return p.node === childNode; });
                        if (childItem) {
                            ctx.beginPath();
                            ctx.moveTo(parentX, parentY + 30);
                            ctx.lineTo(childItem.x, childItem.y - 30);
                            ctx.stroke();
                        }
                    }
                }
            }

        }
    }
    onRootNodeChanged: {
        if (rootWindow.rootNode) {
            calculatePositions();
        }
        canvas.requestPaint();
    }


    function calculatePositions() {
        nodesPositions = [];
        function compute(node, x, y, xOffset) {
            var nodeX = x;
            var nodeY = y;
            nodesPositions.push({ node: node, x: nodeX, y: nodeY });

            var childCount = node.children.length;
            if (childCount === 0) return;

            var childY = y + verticalSpacing;
            var totalWidth = (childCount - 1) * horizontalSpacing;
            var startX = x - totalWidth / 2;

            for (var i = 0; i < childCount; ++i) {
                var child = node.children[i];
                var childX = startX + i * horizontalSpacing;
                compute(child, childX, childY, xOffset / 1.5);
            }
        }

        var startX = 400;
        var startY = 60;
        compute(rootWindow.rootNode, startX, startY, 200);


        var minX = Infinity, maxX = -Infinity, minY = Infinity, maxY = -Infinity;
        for (var i = 0; i < nodesPositions.length; ++i) {
            var x = nodesPositions[i].x;
            var y = nodesPositions[i].y;
            if (x < minX) minX = x;
            if (x > maxX) maxX = x;
            if (y < minY) minY = y;
            if (y > maxY) maxY = y;
        }


        var margin = 50;
        var newWidth = maxX - minX + 2 * margin;
        var newHeight = maxY - minY + 2 * margin;

        var offsetX = margin - minX;
        var offsetY = margin - minY;
        for (var i = 0; i < nodesPositions.length; ++i) {
            nodesPositions[i].x += offsetX;
            nodesPositions[i].y += offsetY;
        }

        canvas.width = newWidth;
        canvas.height = newHeight;
        flickable.contentWidth = newWidth;
        flickable.contentHeight = newHeight;

        canvas.requestPaint();
    }

    onVerticalSpacingChanged: if (rootNode) calculatePositions();
    onHorizontalSpacingChanged: if (rootNode) calculatePositions();


}
