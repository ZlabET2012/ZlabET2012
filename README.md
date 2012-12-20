FirstStage仕様

機能：<br>
　前後方向に尻尾走行をする

クラス・メソッド：<br>
　UI              <br>
　　courseSelect　：　コースを選択する<br>
　　waitStart　　 ：　ユーザからのスタート指示を受け付ける<br>
　TouchSensor　　 <br>
　　isPressed　　 ：　タッチセンサの押下を確認する<br>
　Control         <br>
　　run　　　　　 ：　走行速度と尻尾角度を指定する<br>
　Motor　　　　　 <br>
　　rotate　　　　：　指定された走行速度でモータを回転させる<br>
　Tail            <br>
　　control　　　 ：　指定された尻尾角度まで尻尾を回転させる<br>

ユーザ動作フロー：<br>
　１．起動（NXTのRunボタン）<br>
　２．コースセレクト（NXTのカーソル及びEnterボタン）<br>
　３．スタート（タッチセンサ）<br>
